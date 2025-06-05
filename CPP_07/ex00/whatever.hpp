
template <typename T>
void swap(T& a, T&b)
{
    T buf = a;
    a = b;
    b = buf;
}

template <typename T>
T min(const T& a, const T& b)
{
    return(a < b ? a: b);
}

template <typename T>
T max(const T& a, const T& b)
{
    return((a > b )? a: b);
}