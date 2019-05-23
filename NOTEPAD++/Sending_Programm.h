// Sending function

void send(String F) {
  short int TR[II]; // masiv
  short int count = 0; // kolichestvo oshibok
  short int IO = II - 1; // nepravrlniy for
  short int G = 0; // sostoynie
  short int IJ; //

  do {
    for (IO; IO > 0; IO--) {
      WiFiClient CLI;
      if (G == 0) {
        IJ = IO;
      }
      else {
        IJ = TR[IO];
		sys(1, 1);
      }

      if (CLI.connect(AI[IJ], P)) {
        CLI.print(F);
        CLI.write('\r');
        delay(5);
        CLI.flush();
        CLI.stop();
		sys(0, IJ);
      }
      else {
		sys(2, IO);
        TR[count] = IO;
        count++;
      }
    }
    delay(100);

    IO = count;
    G = 1;
    count = 0;
    while (IO > 0);
  }