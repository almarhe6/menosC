int a[10];

int main()
{ 
    int x;int y;
    bool ok;
    ok = false;
    while (! ok ) {
        read(x); read(y);
        if (((x>=0) && (x<10)) && ((y>=0) && (y<10))) {
            ok = true;
            print(x);
            print(y);
        }
        else {}
  }

    return 0;
}
