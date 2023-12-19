class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& inputImage) {
        // Save the dimensions of the image.
        int rows = inputImage.size();
        int cols = inputImage[0].size();

        // Create temp array of size cols.
        vector<int> temp(cols);
        int prevVal = 0;

        // Iterate over the cells of the image.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Initialize the sum and count 
                int sum = 0;
                int count = 0;

                // Bottom neighbors
                if (i + 1 < rows) {
                    if (j - 1 >= 0) {
                        sum += inputImage[i + 1][j - 1];
                        count += 1;
                    }
                    sum += inputImage[i + 1][j];
                    count += 1;
                    if (j + 1 < cols) {
                        sum += inputImage[i + 1][j + 1];
                        count += 1;
                    }
                }

                // Next neighbor
                if (j + 1 < cols) {
                    sum += inputImage[i][j + 1];
                    count += 1;
                }
                
                // This cell
                sum += inputImage[i][j];
                count += 1;

                // Previous neighbor
                if (j - 1 >= 0) {
                    sum += temp[j - 1];
                    count += 1;
                }

                // Top neighbors
                if (i - 1 >= 0) {
                    // Left-top corner-sharing neighbor.
                    if (j - 1 >=  0) {
                        sum += prevVal;
                        count += 1;
                    }
                    
                    // Top edge-sharing neighbor.
                    sum += temp[j];
                    count += 1;

                    // Right-top corner-sharing neighbor.
                    if (j + 1 < cols) {
                        sum += temp[j + 1];
                        count += 1;
                    }
                }

                // Store the original value of temp[j], which represents
                // the original value of inputImage[i - 1][j].
                if (i - 1 >= 0) {
                    prevVal = temp[j];
                }

                // Save the current value of inputImage[i][j] in temp[j].
                temp[j] = inputImage[i][j];

                // Overwrite with the smoothed value.
                inputImage[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return inputImage;
    }
};
