#include <stdio.h>

// Conversion functions
float to_fahrenheit(float celsius) { return (celsius * 9 / 5) + 32; }
float to_celsius_from_fahrenheit(float fahrenheit) { return (fahrenheit - 32) * 5 / 9; }
float to_kelvin(float celsius) { return celsius + 273.15; }
float to_celsius_from_kelvin(float kelvin) { return kelvin - 273.15; }

// categorization and advisory function
void temperature_advisory(float celsius) {
    if (celsius < 0) printf("t's cold wear layers!\n");
    else if (celsius < 10) printf("a jacket would be wise.\n");
    else if (celsius < 25) printf("perfectly pleasant weather\n");
    else if (celsius < 35) printf("stay cool and hydrated.\n");
    else printf(" extreme heat warning, stay safe indoors.\n");
}

int main() {
    float temp, converted_temp;
    int current_scale, target_scale;

    // prompts for user input
    printf("what temperature you'd like to convert? ");
    scanf("%f", &temp);

    printf("Pick the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &current_scale);

    printf("Convert to: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);

    //  conversion logic 
    if (current_scale == 1 && target_scale == 2)
        converted_temp = to_fahrenheit(temp);
    else if (current_scale == 1 && target_scale == 3)
        converted_temp = to_kelvin(temp);
    else if (current_scale == 2 && target_scale == 1)
        converted_temp = to_celsius_from_fahrenheit(temp);
    else if (current_scale == 3 && target_scale == 1)
        converted_temp = to_celsius_from_kelvin(temp);
    else {
        printf(" invalid choice\n");
        return 0;
    }

    // display result
    printf("\nThe temperature after conversion: %.2f\n", converted_temp);

    // provide user feedback based on input
    temperature_advisory(target_scale == 1 ? converted_temp : to_celsius_from_fahrenheit(converted_temp));

    return 0;
}
