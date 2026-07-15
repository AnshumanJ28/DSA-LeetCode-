class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = image[i].size() - 1;

            while (left <= right) {
                swap(image[i][left], image[i][right]);

                image[i][left] ^= 1;

                if (left != right)
                    image[i][right] ^= 1;

                left++;
                right--;
            }
        }

        return image;
    }
};