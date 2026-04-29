class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        for i in range(1, len(nums)):
            key = nums[i]          # current element to insert
            j = i - 1

            # Move elements of nums[0..i-1] that are greater than key
            # to one position ahead of their current position
            while j >= 0 and nums[j] > key:
                nums[j + 1] = nums[j]
                j -= 1

            # Place key at after the element just smaller than it.
            nums[j + 1] = key

        return nums