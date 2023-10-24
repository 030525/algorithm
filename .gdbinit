set auto-load safe-path /

set print pretty on

layout src

b algorithm.h:17

run ./output/main < input



define n
    next
    info args
    info locals

end

define c
    continue
    info args
    info locals

end


