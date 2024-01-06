import grpc
import calculator_pb2
import time
import calculator_pb2_grpc
if __name__ == '__main__':
    channel = grpc.insecure_channel('127.0.0.1:50051')
    stub = calculator_pb2_grpc.CalculatorStub(channel)
    a = int(input("Enter first number: "))
    b = int(input("Enter second number: "))
    numbers = calculator_pb2.Numbers(a=a, b=b)
    respose = stub.add(numbers)
    print(respose.value)
    respose = stub.sub(numbers)
    print(respose.value)
    respose = stub.mul(numbers)
    print(respose.value)
    respose = stub.div(numbers)
    print(respose.value)
    counter = 0
    while True:
        try:
            start = time.time()
            respose = stub.add(numbers)
            respose = stub.sub(numbers)
            respose = stub.mul(numbers)
            respose = stub.div(numbers)
            # print(respose.value)
            end = time.time()
            # print("Time taken: ",end-start)
            counter += 1
            if counter >= 10000:
                print("Average time taken for 10000 requeests: ",
                      (end-start)/counter)
                counter = 0
        except KeyboardInterrupt:
            break
