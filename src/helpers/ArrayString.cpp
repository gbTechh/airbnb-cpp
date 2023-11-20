#include <iostream>
#include <stdexcept>
#include <cstring>
#include "./ArrayString.h"

#define RED_TEXT "\033[1;31m"
#define RESET_TEXT "\033[0m"

ArrayString::ArrayString(int rows, int columns) {
    this->rows = 0;
    this->columns = 0;
    this->capacityRows = rows;
    this->capacityColumns = columns;
    this->length = rows;

    // Inicializar array bidimensional de char*
    elements = new char**[capacityRows];
    for (int i = 0; i < capacityRows; ++i) {
        elements[i] = new char*[capacityColumns];
    }
}

ArrayString::ArrayString() : ArrayString(10, 10) {
  this->length = this->rows;
}

ArrayString::~ArrayString() {
    // Liberar memoria
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            delete[] elements[i][j];
        }
        delete[] elements[i];
    }
    delete[] elements;
}

void ArrayString::push(const char* element) {
    if (rows == capacityRows || columns == capacityColumns) {
        // Redimensionar si es necesario
        int newCapacityRows = 2 * capacityRows;
        int newCapacityColumns = 2 * capacityColumns;

        char*** newElements = new char**[newCapacityRows];
        for (int i = 0; i < newCapacityRows; ++i) {
            newElements[i] = new char*[newCapacityColumns];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                newElements[i][j] = elements[i][j];
            }
            delete[] elements[i];
        }
        delete[] elements;

        elements = newElements;
        capacityRows = newCapacityRows;
        capacityColumns = newCapacityColumns;
    }

    // Copiar el elemento
    elements[rows][columns] = new char[strlen(element) + 1];
    strcpy(elements[rows][columns], element);

    columns++;
    if (columns == capacityColumns) {
        columns = 0;
        rows++;
    }
}

const char* ArrayString::getIndex(int row, int column) {
    if (row >= rows || column >= columns) {
        throw std::invalid_argument(RED_TEXT "Error: El índice de ArrayString es mayor a la longitud. getIndex() method" RESET_TEXT);
    }
    return elements[row][column];
}

const char* ArrayString::pop() {
    if (rows == 0 || columns == 0) {
        throw std::out_of_range(RED_TEXT "Error: No hay elementos para hacer pop en ArrayString" RESET_TEXT);
    }

    const char* lastItem = elements[rows - 1][columns - 1];
    delete[] elements[rows - 1][columns - 1];

    columns--;
    if (columns < 0) {
        columns = capacityColumns - 1;
        rows--;
    }

    return lastItem;
}

const char* ArrayString::shiftIndex(int row, int column) {
    if (row >= rows || column >= columns) {
        throw std::invalid_argument(RED_TEXT "Error: El índice de ArrayString es mayor a la longitud. shiftIndex() method" RESET_TEXT);
    }

    const char* itemDeleted = elements[row][column];
    delete[] elements[row][column];

    // Hacer el shift
    for (int i = row; i < rows; ++i) {
        for (int j = (i == row) ? column + 1 : 0; j < columns - 1; ++j) {
            elements[i][j] = elements[i][j + 1];
        }
        if (i < rows - 1) {
            elements[i][columns - 1] = elements[i + 1][0];
        }
    }

    columns--;
    if (columns < 0) {
        columns = capacityColumns - 1;
        rows--;
    }

    return itemDeleted;
}

int ArrayString::getRows() {
    return rows;
}

int ArrayString::getColumns() {
    return columns;
}
