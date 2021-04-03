int n=in.nextInt(), m=in.nextInt();
  long k=in.nextLong();
  long p[]=in.nextLongArray(n);
  long mat[][]=new long[n][n];
  for(int i=0;i<m;i++){
   int x=in.nextInt()-1,y=in.nextInt()-1;
   mat[x][y]++;
  }
  for(int i=0;i<n;i++){
   long sum=0;
   for(int j=0;j<n;j++)
    sum+=mat[i][j];
   sum=modInv(sum, mod);
   for(int j=0;j<n;j++)
    mat[i][j]=(mat[i][j]*sum)%mod;
  }
  mat=matExp(mat, k, mod);
  for(int i=0;i<n;i++){
   long ans=0;
   for(int j=0;j<n;j++)
    ans=(ans+p[j]*mat[i][j])%mod;
   out.print(ans+" ");
  }
  out.println();

  out.close();