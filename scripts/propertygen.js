const propStartIndex = 76;
const count = 50;
const offsetStart = 0x00;
const addOffset = false;

let str = [];

for (let i = 0; i < count; i++) {
    let item = "\tunsigned int unk_" + (i + propStartIndex) + ";";

    if(addOffset) {
        item += " // 0x" + (offsetStart + i * 4).toString(16);
    }

    str.push(item);
}

console.log(str.join("\n"));
