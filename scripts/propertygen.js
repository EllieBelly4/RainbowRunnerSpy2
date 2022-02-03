const propStartIndex = 0;
const count = 35;
const offsetStart = 0x68+4;
const addOffset = true;

let str = [];

for (let i = 0; i < count; i++) {
    let item = "\tunsigned int unk_" + (i + propStartIndex) + ";";

    if(addOffset) {
        item += " // 0x" + (offsetStart + i * 4).toString(16);
    }

    str.push(item);
}

console.log(str.join("\n"));
