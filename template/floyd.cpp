for(k=0;k<n;++k)
        {
            for(i=0;i<n;++i)
            {
                for(j=0;j<n;++j)
                {
                    if(know[i][k]+know[k][j]<know[i][j])
                    {
                        know[i][j]=know[i][k]+know[k][j];
                    }
                }
            }
        }