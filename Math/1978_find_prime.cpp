#include <iostream>


int    isPrime(int n);

int    main()
{
    int    n;
    int    cnt = 0;
    int    input;
    
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        cnt += isPrime(input);
    }
    std::cout << cnt;
    
    return 0;
}

int    isPrime(int n)
{
    unsigned int    i;
    
    if (n < 2)
        return 0;
    i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}