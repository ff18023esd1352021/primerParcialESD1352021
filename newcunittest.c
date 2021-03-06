/*
 * File:   newcunittest.c
 * Author: josue
 *
 * Created on 8 sep. 2021, 18:42:03
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void Leermatriz_transpuesta();

void testLeermatriz_transpuesta() {
    Leermatriz_transpuesta();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void multiplicacion_matriz1();

void testMultiplicacion_matriz1() {
    multiplicacion_matriz1();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void leer_matriz();

void testLeer_matriz() {
    leer_matriz();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testLeermatriz_transpuesta", testLeermatriz_transpuesta)) ||
            (NULL == CU_add_test(pSuite, "testMultiplicacion_matriz1", testMultiplicacion_matriz1)) ||
            (NULL == CU_add_test(pSuite, "testLeer_matriz", testLeer_matriz))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
