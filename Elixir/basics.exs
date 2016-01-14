# basic math (answers in floating point) and var assignment
meaningOfLife = ((2 + 2) - 2) + (10*8)/2

# use IO.puts function to output to screen
# IO.puts returns an atom --> :ok
IO.puts (IO.puts meaningOfLife) == :ok

# "atoms" are symbols where their names are their values
IO.puts :hello

# but note that they are *NOT* considered strings
# consider the output of this boolean comparison (false)
IO.puts "hello" == :hello

# the booleans true and false are actually atoms in elixir
IO.puts true == :true

# you can achieve formatted printing in the following way
name = "shafeen"
IO.puts "hello, #{name}"

# this is how you define (and use) an anonymous function
# note that "<>" is the string concatenation operator
add = fn arg1, arg2 -> arg1 + arg2 end
IO.puts Integer.to_string(add.(22, 20)) <> " is the meaning of life"

# anonymous functions are closures and have access
# to variables in the scope they were defined
# note the use of meaningOfLife even though it was defined outside
printMeaningOfLife = fn -> IO.puts meaningOfLife end
printMeaningOfLife.()
