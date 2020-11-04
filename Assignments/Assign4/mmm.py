def mmm(array):
    min = 100000000000
    max = -min
    sum = 0
  # TBD - Start of Code.
    for item in array:
        if item < min:
            min = item
        if item > max:
            max = item
        sum += item
    mean = sum / len(array)
    return (min,max, mean)

data = [((n % 100)+100) for n in range(0,100000)]
(min, max, mean) = mmm(data)
print("Min = %d, Max = %d, Sum = %.2f" % (min, max, mean))

