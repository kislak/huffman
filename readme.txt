Implement a hurchiver with following interface:
huff ifile [-c|-x] ofile
Implement a make-file for building the archiver with 'all' and 'clean' targets.

8-bit

- c11

- mind speed

archive: 
huff input.txt -c out

extract: 
huff out -x input2.txt

? get random data from dd

File.open('five.txt', 'w') do |file|
  20.times do |i|
    ((2**i-1)+1).times do
      12.times do |j|
        file.putc i+ 20 * j
       end
    end
  end
  (20..255).each do |i|
      file.putc i
  end
end
