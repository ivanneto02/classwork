# ICE7 Task 1
class Factory {
	public:
		Factory() : {};
		
		virtual Widget* createButton() const = 0;
		virtual Widget* createMenu() const = 0;
};

class WinFactory : public Factory {
	
	public:
		WinFactory() : {};
		
		virtual Widget* createButton const override;
		virtual Widget* createMenu const override;
};

class LinuxFactory : public Factory{
	
	public:
		LinuxFactory() : {};
		
		virtual Widget* createButton const override;
		virtual Widget* createMenu const override;
};

# ICE7 Task 2
int main() {
	
	Factory* factory;
	
	#ifdef LINUX
		factory = new LinuxFactory();
	#else
		factory = new WindowsFactory();
	#endif
	
	Client *c = new Client(factory)
	c->draw();
}