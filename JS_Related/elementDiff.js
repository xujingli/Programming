function diff(oldArray, newArray) {
  let lastIndex = 0;
  for (const ele of newArray) {
    let mountIndex = oldArray.indexOf(ele);
    if (mountIndex < lastIndex) {
      console.log(mountIndex, '移动到', lastIndex);
    } else {
      lastIndex = Math.max(lastIndex, mountIndex);
    }
  }
}

diff(['A', 'B', 'C', 'D', 'E'], ['D', 'E', 'C', 'B', 'A'])