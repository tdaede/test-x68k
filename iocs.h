static inline short B_KEYINP(void) {
    register unsigned long d0 __asm("d0") = 0;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : 
        : "memory");
    return d0;
}

static inline long B_KEYSNS(void) {
    register unsigned long d0 __asm("d0") = 1;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : 
        : "memory");
    return d0;
}

static inline long B_SFTSNS(void) {
    register unsigned long d0 __asm("d0") = 2;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : 
        : "memory");
    return d0;
}

static inline void KEY_INIT(char d1_b) {
    register unsigned long d0 __asm("d0") = 3;
    register long d1 __asm__("d1") = d1_b;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
}

static inline char BITSNS(short d1_w) {
    register unsigned long d0 __asm("d0") = 4;
    register long d1 __asm__("d1") = d1_w;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
    return d0;
}

static inline void SKEYSET(long d1_l) {
    register unsigned long d0 __asm("d0") = 5;
    register long d1 __asm__("d1") = d1_l;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
}

static inline void LEDCTRL(char d1_b) {
    register unsigned long d0 __asm("d0") = 6;
    register long d1 __asm__("d1") = d1_b;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
}

static inline void LEDSET(void) {
    register unsigned long d0 __asm("d0") = 7;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : 
        : "memory");
}

static inline void KEYDLY(char d1_b) {
    register unsigned long d0 __asm("d0") = 8;
    register long d1 __asm__("d1") = d1_b;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
}

static inline void KEYREP(char d1_b) {
    register unsigned long d0 __asm("d0") = 9;
    register long d1 __asm__("d1") = d1_b;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
}

static inline void TVCTRL(long d1_l) {
    register unsigned long d0 __asm("d0") = 12;
    register long d1 __asm__("d1") = d1_l;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
}

static inline long LEDMOD(long d1_l, char d2_b) {
    register unsigned long d0 __asm("d0") = 13;
    register long d2 __asm__("d2") = d2_b;
    register long d1 __asm__("d1") = d1_l;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d2), "r"(d1)
        : "memory");
    return d0;
}

static inline char TGUSEMD(char d1_b, char d2_b) {
    register unsigned long d0 __asm("d0") = 14;
    register long d2 __asm__("d2") = d2_b;
    register long d1 __asm__("d1") = d1_b;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0), "+r"(d2)
        : "r"(d2), "r"(d1)
        : "memory");
    return d2;
}

static inline long DEFCHR(short d1_hw, short d1_w, unsigned char* a1_l) {
    register unsigned long d0 __asm("d0") = 15;
    register unsigned char* a1 __asm__("a1") = a1_l;
    register long d1 __asm__("d1") = (d1_hw << 16) | d1_w;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(a1), "r"(d1)
        : "memory");
    return d0;
}

static inline void CRTMOD(short d1_w) {
    register unsigned long d0 __asm("d0") = 16;
    register long d1 __asm__("d1") = d1_w;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
}

static inline void CONTRAST(char d1_b) {
    register unsigned long d0 __asm("d0") = 17;
    register long d1 __asm__("d1") = d1_b;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d1)
        : "memory");
}

static inline long HSVTORGB(long d1_l) {
    register unsigned long d0 __asm("d0") = 18;
    register long d1 __asm__("d1") = d1_l;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0), "+r"(d1)
        : "r"(d1)
        : "memory");
    return d1;
}

static inline long TPALET(char d1_b, long d2_l) {
    register unsigned long d0 __asm("d0") = 19;
    register long d2 __asm__("d2") = d2_l;
    register long d1 __asm__("d1") = d1_b;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d2), "r"(d1)
        : "memory");
    return d0;
}

static inline long TPALET2(char d1_b, long d2_l) {
    register unsigned long d0 __asm("d0") = 20;
    register long d2 __asm__("d2") = d2_l;
    register long d1 __asm__("d1") = d1_b;
    __asm__ __volatile__ ("trap $15"
        : "+r"(d0)
        : "r"(d2), "r"(d1)
        : "memory");
    return d0;
}

