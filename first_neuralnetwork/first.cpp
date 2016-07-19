//#include<iostream>
//
//#define MAX2(a,b) (a) > (b) ? (a) : (b)
//
//
//class Neuron
//{
//public:
//	double w_; //weight of one input
//	double b_; //bias of
//
//	double getAct(const double& x)
//	{
//		//for linear or identity activation functions
//		return x;
//
//		//for ReLU activation functions
//		//return MAX2(0.0, x);
//	}
//	double feedForward(const double& input)
//	{
//		//output y = f(\sigma)
//		// \sigma = w_ * input x +b
//		// for multiple inputs,
//		// \sigma = w0_ * x_0+ w1_ * x_1 + ..... + b 
//		const double sigma = w_ * input + b_;
//
//		return getAct(sigma);
//	}
//	
//
//};
//void main()
//{
//	Neuron my_neuron;
//	my_neuron.w_ = 2.0;//가장 적절한 w 와 b를 구해가는 AI의 훈련과정이 중요하다.
//	my_neuron.b_ = 1.0;
//	std::cout << "Input = 0.0은 " << my_neuron.feedForward(0.0) << std::endl;
//	std::cout << "Input = 1.0은 " << my_neuron.feedForward(1.0) <<std::endl;
//	std::cout << "Input = 2.0은 " << my_neuron.feedForward(2.0) << std::endl;
//	std::cout << "Input = 3.0은 " << my_neuron.feedForward(3.0) << std::endl;
//}