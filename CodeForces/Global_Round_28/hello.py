min_sum = 0
n = 4
k = 2
arr = [3, 1, 2, 4]
for j in range(n-k+1):
    min_sum += min(arr[j:j+k])

    print("arr[j:k] : ",arr[j:j+k])
    print("min : ",min(arr[j:j+k]))
    print("min_sum : ",min_sum)

last_num = (int((n+1)/k)) * ((n+1)%k)
print("last_num: ",(n+1)%k)
print("last_num: ",last_num)
min_sum_bt = (sum(range(1,int((n+1)/k))) * k) + last_num
print("min_sum_bt: ",min_sum_bt)
if ( min_sum != min_sum_bt ):
    print("NO")
else:
    print("YES")

print("Sum: ",min_sum)