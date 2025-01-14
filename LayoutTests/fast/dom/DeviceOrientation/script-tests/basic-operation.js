description('Tests the basic operation of DeviceOrientation using the mock.');

var mockAlpha = 1.1;
var mockBeta = 2.2;
var mockGamma = 3.3;
var mockAbsolute = true;

if (window.testRunner)
    testRunner.setMockDeviceOrientation(true, mockAlpha, true, mockBeta, true, mockGamma, true, mockAbsolute);
else
    debug('This test can not be run without the TestRunner');

var deviceOrientationEvent;
window.addEventListener('deviceorientation', function(e) {
    deviceOrientationEvent = e;
    shouldBe('deviceOrientationEvent.alpha', 'mockAlpha');
    shouldBe('deviceOrientationEvent.beta', 'mockBeta');
    shouldBe('deviceOrientationEvent.gamma', 'mockGamma');
    shouldBe('deviceOrientationEvent.absolute', 'mockAbsolute');
    finishJSTest();
});

window.jsTestIsAsync = true;
