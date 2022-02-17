#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

bool IsOverdrawn(float balance)
{
    if (balance < 0)
    {
        return true;
    }
    else
        return false;
}

float AdjustIngredient( float originalAmount, float batches )
{
    return originalAmount * batches; // TODO: Update me!
}

bool IsInputValid( int choice, int min, int max )
{
    if (choice <= max && choice >= min)
    {
        return true;
    }
    else
        return false; // TODO: Update me!
}

float Average( float arr[], int arraySize )
{
    float sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum = sum + arr[i];
    }
    return sum / arraySize; // TODO: Update me!
}

int Summation( int n )
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    return sum; // TODO: Update me!
}

#endif
