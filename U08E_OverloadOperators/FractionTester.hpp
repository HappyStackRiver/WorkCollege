#ifndef _FRACTION_TESTER_HPP
#define _FRACTION_TESTER_HPP

class FractionTester
{
    public:
    void RunTests();

    void Test_DefaultConstructor();
    void Test_ParameterizedConstructor();
    void Test_CopyConstructor();
    void Test_Set();
    void Test_SetNumerator();
    void Test_GetNumerator();
    void Test_SetDenominator();
    void Test_GetDenominator();
    void Test_GetDecimal();
    void Test_CommonDenominatorize();
    void Test_Assignment();
    void Test_Add();
    void Test_Subtract();
    void Test_Multiply();
    void Test_Divide();
    void Test_IsEqual();
    void Test_IsNotEqual();
    void Test_IsLessThan();
    void Test_IsGreaterThan();
    void Test_IsLessThanOrEqualTo();
    void Test_IsGreaterThanOrEqualTo();
};

#endif
