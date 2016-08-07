function jQueryPromises() {

    // prefer the deferred and promise objects
    var deferred = $.Deferred();
    var promise = deferred.promise();

    // prepare the function you want to attach the promise for
    function myFunc() {
        console.log("this is my function running");
    }

    // decide what to do when myFunc completes running
    promise.then(function () {
        console.log("this is the 2nd function running");
    }).then(function () {
        console.log("this is the 3rd function running");
    });

    // resolve your original function at a time you choose
    deferred.resolve(myFunc());
}