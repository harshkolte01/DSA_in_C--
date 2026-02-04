# Lecture 5 - Functions in C++

## Key Concepts

### Function Basics
- **Function**: Reusable block of code that performs a specific task
- **Syntax**: `returnType functionName(parameters) { // code }`

### Parameters vs Arguments
- **Parameters**: Variables in function definition (`int n, int r`)
- **Arguments**: Actual values passed when calling (`binomial(8, 2)`)

### Return Statement
- Returns a value back to the caller
- Must match the return type declared
- Use `void` if function doesn't return anything

### Call by Value
- Copy of argument is passed to function
- Original variable remains unchanged
- Changes inside function don't affect original

### Function in Memory
- Each function call creates a new **stack frame**
- Contains local variables and parameters
- Frame is destroyed when function ends
- Original variables stay in caller's frame

## Functions Implemented

1. **minNum()** - Find minimum of two numbers
2. **nFactorial()** - Calculate factorial
3. **sumOfDigit()** - Sum all digits of a number
4. **binomial()** - Calculate nCr (combinations)
5. **checkPrime()** - Check if number is prime
6. **printNPrime()** - Print first n prime numbers
7. **Fibonacci()** - Print first n Fibonacci numbers

## Important Points
- Function must be declared before use
- Parameters are copies (call by value)
- Return type must match what function returns
- `void` functions don't return values
