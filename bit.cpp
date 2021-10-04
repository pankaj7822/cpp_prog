//Array ka indexing 1 se start hota hai BIT 
void update(int i, int x){ // array ke ith(1 based) index paar x increment karte
  for(;i<N;i+=(i&-i))      // hai then bit tree ko update karne ke liye 
    bit[i]+=x;
}

int sum(int i){ // ith index(1 based) taak sum nikalne ke liye
    int ans=0;
    for(;i>0;i-=(i&i))
    ans+=bit[i];
    return ans;
}