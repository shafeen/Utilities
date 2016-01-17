# this is how you define a dictionary-ish (keyword lists)
# since they are simply lists they DON'T offer constant-time lookup
# keys are ALWAYS atoms
person = [{:name, "John Doe"}, {:age, 100}]
IO.puts person[:name]
IO.puts person[:age]

# you can also define a keyword list this way below
# (which is syntactically equivalent to above)
person = [name: "John Doe", age: 100]
IO.puts person[:name]
IO.puts person[:age]

# you can use ++/-- on any list including keyword lists
person = person ++ [wife: "Jane Doe"]
IO.puts person[:wife]

# elixir keyword lists can have a keyword more than once
# only the first keyword added will be returned on lookup
# if first keyword is removed, the second one will return
# this indicates that the keyword list is ordered
person = person ++ [name: "James Doe"]
IO.puts person[:name]
person = person -- [name: "John Doe"]
IO.puts person[:name]


