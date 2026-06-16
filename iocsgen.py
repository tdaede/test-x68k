#!/usr/bin/env python3

import yaml

def shifted(param):
    if 'h' in param:
        if 'w' in param:
            return "(" + param + " << 16)"
        else:
            return "(" + param + " << 8)"
    else:
        return param

def get_type(reg):
    if reg[0] == "a":
        return "unsigned char*"
    try:
        suffix = reg.split('.')[1]
        if suffix == "b":
            return "char"
        elif suffix == "hb":
            return "char"
        elif suffix == "w":
            return "short"
        elif suffix == "hw":
            return "short"
        else:
            return "long"
    except IndexError:
        return "long"

with open("iocs.yaml") as f:
    iocs = yaml.safe_load(f)
    for call, p in iocs.items():
        in_params = []
        if p and "in" in p:
            if isinstance(p["in"], list):
                in_params.extend(p["in"])
            else:
                in_params.append(p["in"])
        in_regs = set(x[:2] for x in in_params)
        print("static inline ", end='')
        if p and "out" in p:
            print(get_type(p["out"]) + " ", end='')
        else:
            print("void ", end='')
        print(call.upper() + "(", end='')
        if len(in_params):
            print(", ".join([get_type(i) + " " + i.replace('.','_') for i in in_params]), end='')
        else:
            print("void", end='')
        print(") {")
        print('    register unsigned long d0 __asm("d0") = ' + str(p["n"]) + ';')
        for reg in in_regs:
            print('    register ' + get_type(reg) + ' ' + reg + ' __asm__("' + reg + '") = ', end='')
            print(" | ".join([shifted(p).replace('.','_') for p in in_params if p[:2] == reg]) + ";")
        print('    __asm__ __volatile__ ("trap $15"')
        print('        : "+r"(d0)', end='')
        if "out" in p and p["out"][:2] != "d0":
            if p["out"][:2] in in_regs:
                print(', "+r"(' + p["out"][:2] + ')')
            else:
                print(', "r"(' + p["out"][:2] + ')')
        else:
            print()
        print('        : ', end='')
        print(", ".join(['"r"(' + reg + ')' for reg in in_regs if reg != 'd0']))
        print('        : "memory");')
        if "out" in p:
            print('    return ' + p["out"][:2] + ';')
        print("}")
        print()
