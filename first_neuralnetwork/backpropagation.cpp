#include<iostream>
#define MAX2(a,b) (a) > (b) ? (a) : (b)


class Neuron
{
public://Attributes
	Neuron()
		: w_(2.0), b_(1.0)
	{}

	Neuron(const double& w_input, const double& b_input)
		: w_(w_input), b_(b_input)
	{}

public://Behaviours
	double w_; //weight of one input
	double b_; //bias of

	double input_, output_; //saved for back-propagation

	double getAct(const double& x)
	{
		//for linear or identity activation functions
		return x;

		//for ReLU activation functions
		//return MAX2(0.0, x);
	}
	
	double getActGrad(const double&  x)
	{
		//for linear or identity activation functions
		return 1.0; //x를 x에대해 미분하면 1이잖아

		//for ReLU activation functions
		//if(x>0.0) return 1.0;else 0.0;
		
	}
	double feedForward(const double& _input)
	{
		input_ = _input;
		
		//output y = f(\sigma)
		// \sigma = w_ * input x +b
		// for multiple inputs,
		// \sigma = w0_ * x_0+ w1_ * x_1 + ..... + b 
		const double sigma = w_ * input_ + b_;

		output_ = getAct(sigma);

		return output_;
	}
	void feedForwardAndPrint(const double& input)
	{
		printf("%f %f \n", input, feedForward(input));
	}
	void propBackward(const double& target)
	{
		const double alpha = 0.1;// learning rate 
		
		const double grad = (output_ - target) * getActGrad(output_);

		w_ -=  alpha * grad * input_;//last input came from d(wx+b)/dw =x
		b_ -=  alpha * grad * 1.0;//last 1.0 came from d(wx+b)/db = 1
	}

	
	

};
void main()
{
	//initialize my_neuron
	Neuron my_neuron(2.0, 1.0);
	for (int r = 0; r < 100; r++)
	{
		std::cout << "Training " << r << std::endl;
		my_neuron.feedForwardAndPrint(1.0);
		my_neuron.propBackward(4.0);
		std::cout << "w =" << my_neuron.w_ << " b= " << my_neuron.b_ << std::endl;
	}
}