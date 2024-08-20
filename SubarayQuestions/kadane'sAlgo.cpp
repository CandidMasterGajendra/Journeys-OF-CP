// How Does It Work?

// Rules:

//     Maximum subarray sum at every index = maximum subarray sum at previous index + element value at index
//     If max sum at an index is < 0, set sum at that index to 0.
//     MaxSum(index) = Max(MaxSum(index - 1) + arr[index], 0)

int ans = a[0], ans_l = 0, ans_r = 0;
int sum = 0, minus_pos = -1;

for (int r = 0; r < n; ++r) {
    sum += a[r];
    if (sum > ans) {
        ans = sum;
        ans_l = minus_pos + 1;
        ans_r = r;
    }
    if (sum < 0) {
        sum = 0;
        minus_pos = r;
    }
}
