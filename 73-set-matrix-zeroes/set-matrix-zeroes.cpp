class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstCol = false;

        // Step 1: Use first row and first column as markers
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                firstCol = true;

            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Set elements to zero based on markers
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;
        }

        // Step 4: Handle the first column
        if (firstCol)
        {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
    }
};