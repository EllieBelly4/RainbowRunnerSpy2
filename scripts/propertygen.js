const propStartIndex = 0;
const count = 19;
const offsetStart = 0x6c;
let str = [];

for (let i = 0; i < count; i++) {
    str.push("\tunsigned int unk_" + (i + propStartIndex) + "; // 0x" + (offsetStart + i * 4).toString(16));
}

console.log(str.join("\n"));
