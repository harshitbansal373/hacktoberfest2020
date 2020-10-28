def fibonacci(n)
  first_num, second_num = [0, 1]
  (n - 1).times do
    first_num, second_num = second_num, first_num + second_num
  end
  puts first_num
end

fibonacci(10)
