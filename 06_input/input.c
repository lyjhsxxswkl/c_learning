int mat_input_data(Matrix *A)
{
    puts("Please enter your matrix's data ( separated by space )");

    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->col; j++)
        {
            int status;
            do
            {

                status = scanf(MAT_SCANF, &A->data[i][j]);
                if (status == -1)
                {
                    return 0;
                }
                if (status != 1 || isinf(A->data[i][j]) != 0 || fabs(A->data[i][j]) > 1e3)
                {
                    puts("You enter the character. Please enter number under 1000 again");
                    int ch = 0;
                    while ((ch = getchar()) != EOF && ch != '\n')
                }
            } while (status != 1 || isinf(A->data[i][j]) != 0 || fabs(A->data[i][j]) > 1e3);
        }
    }
    return 1;