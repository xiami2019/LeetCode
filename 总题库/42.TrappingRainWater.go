func trap(height []int) int {
	left, right := 0, len(height) - 1
	leftMax, rightMax, ans := 0, 0, 0

	for ; left < right; {
		if height[left] < height[right] {
			if height[left] > leftMax {
				leftMax = height[left]
			}
			else {
				ans += leftMax - height[left]
			}
		}
		else {
			if height[right] > rightMax {
				rightMax = height[right]
			}
			else {
				ans += rightMax - height[right]
			}
		}
	}
	return ans
}