const propStartIndex = 20;
const count = 50;
const offsetStart = 0x00;
let str = [];

for (let i = 0; i < count; i++) {
    str.push("\tunsigned int unk_" + (i + propStartIndex) + "; // 0x" + (offsetStart + i * 4).toString(16));
}

console.log(str.join("\n"));
