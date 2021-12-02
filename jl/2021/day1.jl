function parse_input(year, day)
    [parse(Int64, x) for x in split(open(f->read(f, String), "input/$year/$day"), "\n")]
end

inputs = parse_input(2021, 1)

sums = [a + b + c for (a, b, c) ∈ zip(inputs[1:end-2], inputs[2:end-1], inputs[3:end])]
(partone, parttwo) = [count(diff(inputs) .> 0), count(diff(sums) .> 0)]

println("Part One: $partone\nPart Two: $parttwo")
