#define MAX_COL 100
typedef struct{
    int row;
    int col;
    int value;
}term;

void fast_trnaspose(term a[], term b[])
{
    int row_terms[MAX_COL];
    int starting_pos[MAX_COL];
    
    int Matrix_col_sum=a[0].col;
    int Not0number=a[0].value;
    
    int i, j;
    b[0].row=Matrix_col_sum;
    b[0].col=a[0].row;
    b[0].value=Not0number;
    
    if(Not0number>0)
    {
        for(i=0; i<Matrix_col_sum; i++)
            row_terms[i]=0;
        
        for(i=1; i<=Not0number; i++)
            row_terms[a[i].col]++;
        
        starting_pos[0]=1;
        
        for(i=1; i<Matrix_col_sum; i++)
            starting_pos[i]=row_terms[i-1]+starting_pos[i-1];
        
        for(i=1; i<=Not0number; i++)
        {
            j=starting_pos[a[i].col]++;
            
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j].value=a[i].value;
        }
    }
}
