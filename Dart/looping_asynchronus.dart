import 'dart:async';

void main() {
  final _controller = StreamController<int>();
  final timer = Timer.periodic(
      const Duration(seconds: 1), (timer) => _controller.sink.add(timer.tick));

  _controller.stream.take(10).listen(
    print,
    onDone: () {
      print('Done looping');
      timer.cancel();
      _controller.close();
    },
  );
}
