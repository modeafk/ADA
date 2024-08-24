#include <iostream>
#include <cstdlib>  // Para malloc, realloc, free
#include <cstring>  // Para memcpy

struct Vector {
    int* m_pVect;   // Pointer to the buffer
    int m_nCount;   // Control how many elements are actually used
    int m_nMax;     // Control how many are allocated as maximum
    int m_nDelta;   // To control the growing

    // Constructor para inicializar un Vector con un tamaño inicial
    Vector(int initialSize = 10, int delta = 10)
        : m_nCount(0), m_nMax(initialSize), m_nDelta(delta) {
        m_pVect = (int*) std::malloc(sizeof(int) * m_nMax);
        if (!m_pVect) {
            std::cerr << "Memory allocation failed!\n";
            std::exit(EXIT_FAILURE);
        }
    }

    // Destructor para liberar la memoria
    ~Vector() {
        std::free(m_pVect);
    }
};

void Resize(Vector* pThis) {
    int newSize = pThis->m_nMax + pThis->m_nDelta;
    int* newBuffer = (int*) std::realloc(pThis->m_pVect, sizeof(int) * newSize);
    if (newBuffer == nullptr) {
        std::cerr << "Memory allocation failed during resize!\n";
        std::exit(EXIT_FAILURE);
    }
    pThis->m_pVect = newBuffer;
    pThis->m_nMax = newSize;
}

void Insert(Vector* pThis, int elem) {
    if (pThis->m_nCount == pThis->m_nMax) { // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem
    }
    pThis->m_pVect[pThis->m_nCount++] = elem; // Insert the element at the end of the sequence
}

int main() {
    Vector myVector; // Create a Vector instance with default size

    // Insert some elements into the vector
    for (int i = 0; i < 20; ++i) {
        Insert(&myVector, i);
    }

    // Print the elements
    std::cout << "Vector elements:\n";
    for (int i = 0; i < myVector.m_nCount; ++i) {
        std::cout << myVector.m_pVect[i] << std::endl;
    }

    return 0;
}
