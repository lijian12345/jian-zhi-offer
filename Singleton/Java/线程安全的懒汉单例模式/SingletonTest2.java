import java.lang.Thread;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class SingletonTest2 {
    public static void main(String... args) {
        ExecutorService service = Executors.newCachedThreadPool();
        service.execute(new MyTask());
        service.execute(new MyTask());
        service.execute(new MyTask());
        service.shutdown();
    }

    private static class MyTask implements Runnable {
        @Override
        public void run() {
            SynchronizedSingleton singleton = SynchronizedSingleton.getInstance();
            System.out.println(Thread.currentThread() + "get the singleton");
            singleton.someFunc();
            System.out.println(Thread.currentThread() + " is over.");
        }
    }
}

class SynchronizedSingleton {
    private static SynchronizedSingleton instance = null;

    public static synchronized SynchronizedSingleton getInstance() {
        if (instance == null) {
            instance = new SynchronizedSingleton();
        }
        return instance;
    }

    public synchronized void someFunc() {
        for (int i = 0; i < 10; i++) {
            try {
                TimeUnit.SECONDS.sleep(1);
                System.out.println(Thread.currentThread() + " invoke someFunc at " + i + " times");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}