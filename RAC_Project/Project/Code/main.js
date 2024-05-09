const btn = document.getElementById("button")

btn.addEventListener("click", ()=> {
    Notification.requestPermission().then(perm => {
        if(perm === "granted"){
            new Notification("door is open !!" , {
                body: "this is more text",
                
            })
        }
    })
})