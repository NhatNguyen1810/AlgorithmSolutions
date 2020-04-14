You are given an n x n 2D matrix representing an image.

/*Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i + 1 ; j < matrix[0].size() ; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i]; 
                matrix[j][i] = tmp; 
            }
            
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size()/2 ; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - j-1]; 
                matrix[i][matrix.size() - j-1] = tmp; 
            }
            
        }
    }
};
