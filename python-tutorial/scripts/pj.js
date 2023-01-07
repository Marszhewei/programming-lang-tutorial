[...document.getElementsByTagName("input")].filter(i=>i.dataset.xDafxsm=="完全符合").forEach(i=>i.click())
[...document.getElementsByTagName("input")].filter(i=>i.dataset.xDafxsm=="非常满意").forEach(i=>i.click())
[...document.getElementsByClassName("bh-txt-input__txtarea")].forEach(i=>i.value=Math.floor(Math.random() * 9) + 1)
