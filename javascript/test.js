


function frontDoorResponse(line) {
    line = line.trim();
    return line[line.length-1];
}
console.log(frontDoorResponse('   hello    '));
