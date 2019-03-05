class BoundsException extends Exception {
    void printError() {
        printStackTrace();
        System.err.println("\nERROR!\n");
    }
}