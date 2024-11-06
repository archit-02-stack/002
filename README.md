import time

def deterministic_quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return deterministic_quick_sort(left) + middle + deterministic_quick_sort(right)

def randomized_quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = random.choice(arr)
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return randomized_quick_sort(left) + middle + randomized_quick_sort(right)

def measure_execution_time(sort_function, arr):
    start_time = time.time()
    sorted_arr = sort_function(arr)
    end_time = time.time()
    return end_time - start_time, sorted_arr

try:
    array_size = int(input("Enter the size of the array: "))
    user_input = input("Enter the array elements separated by space: ")

    sample_array = list(map(int, user_input.split()))
    if len(sample_array) != array_size:
        raise ValueError("The number of entered elements does not match the specified array size.")
except ValueError as e:
    print(f"Invalid input: {e}")
    exit()

det_time, det_sorted_array = measure_execution_time(deterministic_quick_sort, sample_array)
print(f"\nDeterministic Quick Sort took {det_time:.6f} seconds")
print(f"Sorted Array (Deterministic): {det_sorted_array}\n")

rand_time, rand_sorted_array = measure_execution_time(randomized_quick_sort, sample_array)
print(f"Randomized Quick Sort took {rand_time:.6f} seconds")
print(f"Sorted Array (Randomized): {rand_sorted_array}")
