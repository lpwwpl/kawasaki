#include "multi_array.hpp"

Value::Value() {
    dim = NULL;
    data = NULL;
}

Value::Value(int newType, int newDefault) {
    //printf("creating value\n");         //test view
    type = newType;
    ndim = 1;
    dim = new int[ndim];
    dim[0] = 1;
    data = new int* [1];
    data[0] = new int[1];
    data[0][0] = newDefault;
}

Value::Value(int newType, int newDefault, int ndim, int* dim) {
    type = newType;
    (*this).ndim = ndim;
    (*this).dim = new int[ndim];
    data = new int* [ndim];
    for (int count = 0; count < ndim; count++) {
        (*this).dim[count] = dim[count];              //copying dimensions array
        data[count] = new int[dim[count]];
    }
    int count_row = 0;
    for (count_row; count_row < ndim; count_row++)
        for (int count_column = 0; count_column < dim[count_row]; count_column++)
            data[count_row][count_column] = newDefault;
}

Value::Value(int newType, int newDefault, int ndim, dimListType* dim) {
    type = newType;
    (*this).ndim = ndim;
    (*this).dim = new int[ndim];
    data = new int* [ndim];
    for (int count = 0; count < ndim; count++) {
        (*this).dim[count] = (*dim)[count];              //copying dimensions array
        data[count] = new int[(*dim)[count]];
    }
    int count_row = 0;
    for (count_row; count_row < ndim; count_row++)
        for (int count_column = 0; count_column < (*dim)[count_row]; count_column++)
            data[count_row][count_column] = newDefault;
}

void Value::printValue() {
    int count_row = 0;
    std::cout << std::endl;
    for (count_row; count_row < ndim; count_row++)
    {
        for (int count_column = 0; count_column < dim[count_row]; count_column++)
            std::cout << data[count_row][count_column] << "   ";
        std::cout << std::endl;
    }
}

Value::Value(const Value& orig) :type(orig.type), ndim(orig.ndim) {
    dim = new int[orig.ndim];
    data = new int* [ndim];
    for (int count = 0; count < ndim; count++) {
        dim[count] = orig.dim[count];
        data[count] = new int[dim[count]];
    }

    int count_row = 0;
    for (count_row; count_row < ndim; count_row++)
        for (int count_column = 0; count_column < dim[count_row]; count_column++)
            data[count_row][count_column] = orig.data[count_row][count_column];

}

Value& Value::operator =(const Value& right) {
    if (this == &right) {
        return *this;
    }
    if (type != right.type) {       
        exit(0);
    }
    if (ndim != right.ndim) {
        exit(0);
    }
    for (int count = 0; count < ndim; count++) {
        if (dim[count] != right.dim[count]) {
             exit(0);
        }
    }
    int count_row = 0;
    for (count_row; count_row < ndim; count_row++)
        for (int count_column = 0; count_column < dim[count_row]; count_column++)
            data[count_row][count_column] = right.data[count_row][count_column];
    return *this;
}

Value::Value(int ndim) {
    data = new int* [ndim];
    (*this).ndim = ndim;
    dim = NULL;
    type = 2;     //accessVary
}

addressListType* Value::index(dimListType* indexes) {
    if (ndim < indexes->size()) {
        exit(0);
    }
    addressListType* newValues = new addressListType();
    for (int count = 0; count < indexes->size(); count++) {
        if (dim[count] < indexes->at(count)) {
            exit(0);
        }
        newValues->push_back(&data[count][indexes->at(count) - 1]);
    }
    for (int count = indexes->size(); count < ndim; ++count)
        newValues->push_back(&data[count][0]);
    return newValues;

}

Value::~Value() {
    for (int count = 0; count < ndim; count++)
        delete[]data[count];
}


