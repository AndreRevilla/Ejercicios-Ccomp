#include <iostream>
#include <cstdint>
#include <bitset>
#include <cmath>
using namespace std;

//Convertir entre float y su representación en bits
union FloatBits {
    float f;
    uint32_t bits;
};

void extractIEEE754Parts(uint32_t bits, int &sign, int &exponent, uint32_t &mantissa) {
    sign = (bits >> 31) & 0x1;
    exponent = (bits >> 23) & 0xFF;
    mantissa = bits & 0x7FFFFF;
}

void printFloatBits(const string &label, float value) {
    FloatBits fb;
    fb.f = value;
    bitset<32> bits(fb.bits);
    cout << label << " (" << value << "): " << bits << endl;
}

int main() {
    FloatBits A, B, result;
    
    cout << "Ingrese el valor de X: ";
    cin >> A.f;
    cout << "Ingrese el valor de Y: ";
    cin >> B.f;

    int signA, expA, signB, expB;
    uint32_t mantA, mantB;

    extractIEEE754Parts(A.bits, signA, expA, mantA);
    extractIEEE754Parts(B.bits, signB, expB, mantB);

    if (A.f == 0.0f) {
        result.f = 0.0f;
        cout << "X es cero → Z = 0\n";
    } else if (B.f == 0.0f) {
        result.f = INFINITY;
        cout << "Y es cero → Z = inf\n";
    } else {
        int expZ = expA - expB + 127;

        if (expZ >= 255) {
            cout << "¡Overflow de exponente!\n";
            result.f = INFINITY;
        } else if (expZ <= 0) {
            cout << "¡Underflow de exponente!\n";
            result.f = 0.0f;
        } else {
            uint32_t fullMantA = (1 << 23) | mantA;
            uint32_t fullMantB = (1 << 23) | mantB;

            uint32_t mantZ = (static_cast<uint64_t>(fullMantA) << 23) / fullMantB;

            while ((mantZ & (1 << 23)) == 0 && expZ > 0) {
                mantZ <<= 1;
                expZ--;
            }

            mantZ &= 0x7FFFFF;

            uint32_t resultBits = ((signA ^ signB) << 31) | (expZ << 23) | mantZ;
            result.bits = resultBits;
        }
    }

    cout << endl;
    cout << "Resultado: " << (A.f / B.f) << endl;

    // Mostrar resultado en bits
    printFloatBits("X", A.f);
    printFloatBits("Y", B.f);
    printFloatBits("Z", result.f);

    return 0;
}
