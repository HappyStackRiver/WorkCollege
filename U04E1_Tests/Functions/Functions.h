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
    return false; // TODO: Update me!
}

bool IsInputValid( int choice, int min, int max )
{
    return false; // TODO: Update me!
}

float Average( float arr[], int arraySize )
{
    return 0; // TODO: Update me!
}

int Summation( int n )
{
    return 0; // TODO: Update me!
}

#endif
