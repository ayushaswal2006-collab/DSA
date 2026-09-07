double myPow(double x, int n) {
    if(x==0)
    return 0;
    if(x==1)
    return 1;
    if(x==-1 && n%2==0)
    return 1;
    if(x==-1 && n%2!=0)
    return -1;
    long m=n;
    if(m<0){
        m=-m;
        x=1/x;
    }
    double sol=1;
    while(m>0){
        if(m%2==1)
        sol*=x;
        x*=x;
        m/=2;
    }
    return sol;
    }