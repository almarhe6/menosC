struct { int a; bool b; int c; } r;

int main()
{
    int x;
    read (x);
    r.a = 10+x;
    r.b = false;
    r.c = -10-x;
    print(x);
    print(r.a);
    print(r.c);

  return 0;
}
