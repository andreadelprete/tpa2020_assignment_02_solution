//
// Created by olli on 10/05/20.
//

#ifndef SECONDASSIGNMENT_BATCHSIMULTAION_H
#define SECONDASSIGNMENT_BATCHSIMULTAION_H

#include "liblinalg/Vector.h"
#include "libsimcon/Simulable.h"

Vector ***batchSimulation(Simulable **simulators, int n, int simSteps) {
    // Constructing a matrix of elements
    auto res = new Vector **[simSteps];

    for (int i = 0; i < simSteps; ++i) {
        res[i] = new Vector *[n];
        for (int j = 0; j < n; ++j) {
            simulators[j]->simulate();
            res[i][j] = simulators[j]->getX();
        }

        for (int k = 0; k < n; ++k) {
            std::cout << res[i][k]->transpose().toString() << "\t";
        }
        std::cout << std::endl;
    }

    return res;
}

void deallocateSimData(Vector ***data, int n, int simSteps) {
    for (int i = 0; i < simSteps; ++i) {
        for (int j = 0; j < n; ++j) {
            delete data[i][j];
        }
        delete[] data[i];
    }
    delete[] data;
}

#endif //SECONDASSIGNMENT_BATCHSIMULTAION_H
